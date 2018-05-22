using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
// Bibliotecas para leitura/ GRavação de arquivos
using System.IO;
using Microsoft.Win32; // janelas de dialogo abrir/salvar arquivos
using AppManager;




namespace Arquivo
{
    /// <summary>
    /// Interação lógica para MainWindow.xam
    /// </summary>
    public partial class MainWindow : Window
    {
        AppException appex = new AppException();
        //Instacias das janelas de dialogo

        private OpenFileDialog DialogoAbrir = null;
        private SaveFileDialog DialogoSalvar = null;
        // contem o caminho completo do arquivo sendo editado
        private string caminho = "";

        public MainWindow()
        {
            InitializeComponent();

            //Janela Abrir
            DialogoAbrir = new OpenFileDialog
            {
                Filter = "txt|*.txt",
                AddExtension = true
            };
            //Define o metodo que será executado quando pressionado OK
            DialogoAbrir.FileOk += AbrirArquivoOk;

            //Janela Salvar
            DialogoSalvar = new SaveFileDialog
            {
                Filter = "txt|*.txt",
                AddExtension = true
            };
            DialogoSalvar.FileOk += GravarArquivoOk;

        }

        #region ABRIR ARQUIVO

        private void Abrir_Click(object sender, RoutedEventArgs e)
        {
            DialogoAbrir.ShowDialog();
        }

        private void AbrirArquivoOk (object sender, System.ComponentModel.CancelEventArgs e)
        {

            //Abre o arquivo para leitura
            TextReader reader = null;
            try
            {

               // throw new System.ArgumentException("Parameter cannot be null", "original");
                caminho = DialogoAbrir.FileName;
                FileInfo info = new FileInfo(caminho);
                //abre o arquivo para a leitura
                reader = info.OpenText();
                NomeArquivo.Text = info.Name;
                Conteudo.Text = "";

                // Lê uma linha do arquivo
                string line = reader.ReadLine();
                // Faça enquanto houver conteudo na linha
                while (line != null)
                {
                    Conteudo.Text += line + "\n";
                    //le a proxima linha
                    line = reader.ReadLine();
                }

                Gravar.IsEnabled = false;
                GravarComo.IsEnabled = false;

            }
            catch (Exception ex)
            {

                // tratamento a exceção
                appex.SaveException(ex);
            }
            finally
            {
                //MUITO IMPORTANTE
                if (reader != null) reader.Close();
            }
            

        }

        private void Conteudo_TextChanged(object sender, TextChangedEventArgs e)
        {


            Gravar.IsEnabled = true;
            GravarComo.IsEnabled = true;


        }



        #endregion

        #region SALVAR ARQUIVO

        //Salva os dados de conteudo.text no arquivo
        private void Salvar()
        {
            try
            {
                if (caminho.Trim() == "")
                {
                    DialogoSalvar.ShowDialog();
                }
                else
                {
                    //Grava os dados
                    File.WriteAllText(caminho, Conteudo.Text, Encoding.UTF8);
                    Gravar.IsEnabled = false;
                    GravarComo.IsEnabled = false;
                }
            }
            catch (Exception ex)
            {

                appex.SaveException(ex);
            }

        }

        private void GravarArquivoOk(object sender, System.ComponentModel.CancelEventArgs e)
        {
            caminho = DialogoSalvar.FileName;
            Salvar();
        }

        private void Gravar_Click(object sender, RoutedEventArgs e)
        {
            Salvar();
        }

        private void GravarComo_Click(object sender, RoutedEventArgs e)
        {
            DialogoSalvar.ShowDialog();
        }


        #endregion


        private void Fechar_Click(object sender, RoutedEventArgs e)
        {
            Close();
        }

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {

            if (Gravar.IsEnabled == true)
            {
                MessageBoxResult resposta = MessageBox.Show("Deseja salvar o texto antes?", "FECHAR", MessageBoxButton.YesNoCancel);
                if (resposta == MessageBoxResult.Yes)
                {
                    if (DialogoSalvar.ShowDialog() == true)
                    {
                        Salvar();
                    }
                    else
                    {
                        // Foi pressionado cancelar na janela de dialogo salvar
                        e.Cancel = true;
                    }
                    
                }else if (resposta == MessageBoxResult.Cancel)
                {
                    e.Cancel = true;
                }
            }

        }
    }
}
