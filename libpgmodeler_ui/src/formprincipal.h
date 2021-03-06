/*
# Projeto: Modelador de Banco de Dados PostgreSQL (pgModeler)
# Sub-projeto: Biblioteca libpgsqldbm_ui
# Classe: FormPrincipal
# Descrição: Definição da classe que implementa o formulário principal do software,
#            Reune e gerencia todas as classes das bibliotecas implementadas.
#
# Copyleft 2006-2012 - Raphael Araujo e Silva <rkhaotix@gmail.com>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software Foundation,
# Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
#ifndef FORM_PRINCIPAL_H
#define FORM_PRINCIPAL_H

#include <QtGui>
#include "ui_formprincipal.h"
#include "modelowidget.h"
#include "formsobre.h"
#include "caixamensagem.h"
#include "formbasico.h"
#include "listaoperacoeswidget.h"
#include "visaoobjetoswidget.h"
#include "pgmodelerplugin.h"

using namespace std;
//***********************************************************
class FormPrincipal: public QMainWindow, public Ui::FormPrincipal {
 Q_OBJECT

 private:
  //Atributo estático e constante que guarda a versão atual do pgModeler
  static const QString VERSAO_PGMODELER;

  //Timer de salvamento automático do modelo
  QTimer tm_salvamento;

  //Dockwidget o qual exibe as operações executadas sobre os objetos
  ListaOperacoesWidget *lista_oper;

  //Dockwidget o qual exibe todos os objetos do modelo em forma de árvore/lista
  VisaoObjetosWidget *visao_objs;

  //Armazena a referência para o modelo atualmente aberto
  ModeloWidget *modelo_atual;

  //Armazena o nome da operação atualmente selecionada
  QLabel *nome_op;

  //Armazena o nome ícone da operação atualmente selecionada
  QLabel *icone_op;

  //Título da janela principal
  QString titulo_janela;

  //Armazena o intevalo de salvamento automático do modelo
  int interv_salvar;

  //Mapa de plugins carregados
  map<QString, PgModelerPlugin *> plugins;

  //Armazena as ações criadas para cada plugin
  vector<QAction *> acoes_plugins;

  //Sobrecarga do closeEvent(): Salva as configurações antes do encerramento do aplicativo
  void closeEvent(QCloseEvent *);

  //Sobrecarga do showEvent(): Insere as ações do plugin na barra de plugins (se houver)
  void showEvent(QShowEvent *);

  //Carrega os plugins no diretório plugins/
  void carregarPlugins(void);

  //Destrói todos os plugins carregados
  void destruirPlugins(void);

 public:
   FormPrincipal(QWidget *parent = 0, Qt::WindowFlags flags = 0);
  ~FormPrincipal(void);

 private slots:
  //Atualiza as definições da grade com base nas ações: Exibir Grade, Alin. Grade e Exibir limites
  void definirOpcoesGrade(void);

  /* Adiciona um novo modelo, caso o parâmetro 'nome_arq' esteja preenchido, o pgModeler
     tentará carregar o modelo especificado pelo arquivo */
  void adicionarNovoModelo(const QString &nome_arq="");

  /* Atualiza o estado (ativo/inativo) dos botões das barras
     de ferramentas de acordo com a ação de abertura ou
     fechamento de modelo */
  void atualizarEstadoFerramentas(bool modelo_fechado=false);
  void __atualizarEstadoFerramentas(void);

  /* Efetua a atualização dos dockwidgets de visão geral,
     lista de operações e arvore de objetos */
  void atualizarDockWidgets(void);
  void __atualizarDockWidgets(void);

  //Atualiza a referência ao modelo atual quando as abas de modelos são ativadas
  void definirModeloAtual(void);

  /* Executa o fechamento do modelo atual, o parâmetro 'idx_modelo' pode ser usado
     para fechar um modelo especificado por seu índice */
  void fecharModelo(int idx_modelo=-1);

  //Carrega um modelo a partir do disco
  void carregarModelo(void);

  //Salva um determinado ModeloWidget
  void salvarModelo(ModeloWidget *modelo=NULL);

  //Salva todos os modelos abertos
  void salvarTodosModelos(void);

  //Imprime o modelo atual
  void imprimirModelo(void);

  //Executa a exportação no modelo atual
  void exportarModelo(void);

  //Atualiza os modelos abertos com as novas configurações
  void atualizarModelos(void);

  //Aplica o zoom sobre o modelo atual
  void aplicarZoom(void);

  //Exibe o pgModeler em tela cheia
  void exibirTelaCheia(bool tela_cheixa);

  //Executa o plugin representado pela ação que disparou o slot
  void executarPlugin(void);
};
//***********************************************************
#endif
