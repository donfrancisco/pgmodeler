/*
# Projeto: Modelador de Banco de Dados PostgreSQL (pgsqlDBM)
# Sub-projeto: Biblioteca libutil
# Classe: Excecao
# Data de Criação: 10/07/2006
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
#ifndef EXCECAO_H
#define EXCECAO_H

#include <QObject>
#include <exception>
#include <QString>
//#include <execinfo.h>
#include <signal.h>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;
const int QTD_ERROS=172; //177;

/*
 Formato dos enums de erros: ERR_[BIBLIOTECA]_[ERRO] onde:
 ERRO é composto de:
  CODIGO CLASSE
  CODIGO OPERAÇÃOO: INS=Inserção
                   ATR=Atribuição
                   REF=Referência
                   REM=Remoção
                   DES=Desenho
                   RES=Restauração
                   OBT=Obtenção
  CODIGO ERRO
*/

enum TipoErro {
 ERR_NULO,
 ERR_GLOBAL_OBJBADALOC,
 ERR_PGMODELER_ATRPSDTIPOCOL,
 ERR_PGMODELER_ATRCOMPRIMZERO,
 ERR_PGMODELER_ATRPRECISAOINV,
 ERR_PGMODELER_ATRPRECTIPOTIMEINV,
 ERR_PGMODELER_ATRCOLNAOALOC,
 ERR_PGMODELER_REFCOLIDXINV,
 ERR_PGMODELER_ATROBJNAOALOC,
 ERR_PGMODELER_ATRESQNAOALOC,
 ERR_PGMODELER_ATROBJDEFSQLINV,
 ERR_PGMODELER_ATROBJDUPLIC,
 ERR_PGMODELER_ATROBJDUPLICCONT,
 ERR_PGMODELER_ATROBJTIPOINV,
 ERR_PGMODELER_REMOBJTIPOINV,
 ERR_PGMODELER_OBTOBJTIPOINV,
 ERR_PGMODELER_ATRNOMEVAZIOTPRET,
 ERR_PGMODELER_INSPARAMDUPLIC,
 ERR_PGMODELER_INSTPRETDUPLIC,
 ERR_PGMODELER_REFPARAMIDXINV,
 ERR_PGMODELER_REFEVENTOGATINV,
 ERR_PGMODELER_ATRCOLINVGATILHO,
 ERR_PGMODELER_ATRFUNCNAOALOC,
 ERR_PGMODELER_ATRFUNCGATINV,
 ERR_PGMODELER_ATRFUNCNUMPARAMINV,
 ERR_PGMODELER_ATRFUNCLINGINV,
 ERR_PGMODELER_ATRTABNAOALOC,
 ERR_PGMODELER_REFARGIDXINV,
 ERR_PGMODELER_INSCOLDUPLIC,
 //ERR_PGMODELER_ATRTAMGRADEINV,
 //ERR_PGMODELER_DESSELOBJNAOALOC,
 //ERR_PGMODELER_TIPOOBJINV,
 ERR_PGMODELER_ATRNOMEOBJVAZIO,
 ERR_PGMODELER_ATRNOMEOBJINV,
 ERR_PGMODELER_ATRESQTIPOINV,
 ERR_PGMODELER_ATRESPTABTIPOINV,
 ERR_PGMODELER_ATRESPTABOBJINV,
 ERR_PGMODELER_ATRESPTABRESTTIPOINV,
 ERR_PGMODELER_ATRPAPELTIPOINV,
 ERR_PGMODELER_ATRDONOOBJINV,
 ERR_PGMODELER_REFFUNCTIPOINV,
 ERR_PGMODELER_REFARGOPTIPOINV,
 ERR_PGMODELER_REFOPTIPOINV,
 ERR_PGMODELER_ATROPPAPELTIPOINV,
 ERR_PGMODELER_REFPAPELINV,
 ERR_PGMODELER_INSITEMPAPELDUPLIC,
 ERR_PGMODELER_REFREDUNDANTEPAPEIS,
 ERR_PGMODELER_ATRMEBROPROPPAPEL,
 ERR_PGMODELER_REFPAPELIDXINV,
 ERR_PGMODELER_INSCMDNULO,
 ERR_PGMODELER_REFCMDIDXINV,
 ERR_PGMODELER_HERANCATABINV,
 ERR_PGMODELER_ATROBJRELAC,
 ERR_PGMODELER_ATRESQDIFSEQ,
 ERR_PGMODELER_ATRESQVALORINV,
 ERR_PGMODELER_ATRESQVALORMININV,
 ERR_PGMODELER_ATRESQVALORINIINV,
 ERR_PGMODELER_ATRESQINCNULO,
 ERR_PGMODELER_ATRESQCACHENULO,
 ERR_PGMODELER_ATRESQDIFTAB,
 ERR_PGMODELER_ATRDONODIFTAB,
 ERR_PGMODELER_ATRCOLPOSINDEF,
 ERR_PGMODELER_ATRCOLPOSNAORELAC,
 ERR_PGMODELER_REFROTIDXINV,
 ERR_PGMODELER_ALOCOBJTIPOINV,
 //ERR_PGMODELER_REDOBJNAOALOC,
 ERR_PGMODELER_ATRFUNCRETINV,
 ERR_PGMODELER_ATRFUNCPARAMINV,
 ERR_PGMODELER_ATRLINGNAOALOC,
 ERR_PGMODELER_ATRLINGTIPOINV,
 ERR_PGMODELER_REFTIPOIDXINV,
 ERR_PGMODELER_ATRTIPONULO,
 ERR_PGMODELER_ATRTIPOINVOBJ,
 ERR_PGMODELER_ATRNOMEDIRVAZIO,
 ERR_PGMODELER_OBTQTDTIPOINV,
 ERR_PGMODELER_INSATRIBTIPODUPLIC,
 ERR_PGMODELER_INSATRIBTIPOINV,
 ERR_PGMODELER_INSENUMTIPODUPLIC,
 ERR_PGMODELER_INSENUMTIPOINV,
 ERR_PGMODELER_REFATRIBTIPOIDXINV,
 ERR_PGMODELER_REFENUMTIPOIDXINV,
 ERR_PGMODELER_ATRCONFTIPOINV,
 ERR_PGMODELER_INSTIPODUPLIC,
 ERR_PGMODELER_ATROPFUNCAGRARGINV,
 ERR_PGMODELER_ATROPFUNCAGTIPOSINV,
 ERR_PGMODELER_ATRNOMERESERV,
 ERR_PGMODELER_FUNCCONFIGINV,
 ERR_PGMODELER_ATRIDUSUARIOINV,
 ERR_PGMODELER_ATRVALORINVNUMEST,
 ERR_PGMODELER_INSELEMDUPLIC,
 ERR_PGMODELER_REFELEMIDXINV,
 ERR_PGMODELER_REFOBJIDXINV,
 ERR_PGMODELER_REMOBJNAOALOC,
 ERR_PGMODELER_REMOBJREFERDIR,
 ERR_PGMODELER_REMOBJREFERIND,
 ERR_PGMODELER_OPROBJTIPOINV,
 ERR_PGMODELER_REFOBJTIPOINV,
 ERR_PGMODELER_OPROBJNAOALOC,
 ERR_PGMODELER_RELTABSEMPK,
 ERR_PGMODELER_TIPORELNAOIMPL,
 ERR_PGMODELER_ATREXPRINV,
 //ERR_PGMODELER_REFCOROBJINV,
 ERR_PGMODELER_ATRPKEXISTETAB,
 ERR_PGMODELER_RELIDENTINV,
 ERR_PGMODELER_RELINVCOLDUPLIC,
 ERR_PGMODELER_RELINVCOLSINCOMP,
 ERR_PGMODELER_ATROBJRELINV,
 ERR_PGMODELER_ATRFKRELAC,
 ERR_PGMODELER_REFOBJINEXISTE,
 ERR_PGMODELER_REFTIPOUSRINV,
 ERR_PGMODELER_ATRTAMMAXINVLISTA,
 ERR_PGMODELER_ARQNAOGRAVADO,
 //ERR_PGMODELER_ARQNAOCARREGADO,
 ERR_PGMODELER_ARQNAOGRAVADODEFINV,
 ERR_PGMODELER_RELEXISTEMODELO,
 ERR_PGMODELER_INSRELGERAREDUNDANCIA,
 ERR_PGMODELER_REFCOLUNAINVTABELA,
 ERR_PGMODELER_ALOCPKFORMAINVALIDA,
 ERR_PGMODELER_REFPRIVLEGIOIDXINV,
 ERR_PGMODELER_INSPAPELDUPLICPERM,
 ERR_PGMODELER_ATRPRIVILEGIOOBJINV,
 ERR_PGMODELER_ATRPERMISSAODUPLIC,
 ERR_PGMODELER_PERMREFOBJINEXISTE,
 ERR_PGMODELER_OBJSEMESQUEMA,
 ERR_PGMODELER_ATRESPTABDIRDUPLIC,
 ERR_PGMODELER_ATRDIMENSAOINVDOMINIO,
 ERR_PGMODELER_ATRCORPOFUNCLINGC,
 ERR_PGMODELER_ATRBIBLIOFUNCLINGDIFC,
 ERR_PGMODELER_ATROPERCOMUTINV,
 ERR_PGMODELER_ATROPERNEGINV,
 ERR_PGMODELER_TIPOUSRAUTOREF,
 ERR_PGMODELER_ATRELEMENTOINVTIPO,
 ERR_PGMODELER_ATRALINHAMENTOINVTIPO,
 ERR_PGMODELER_ATRNOMEINVTABRELNN,
 ERR_PGMODELER_PKESPTIPORELINV,

 ERR_PGMODELERUI_OPROBJINCRELACAO,
 ERR_PGMODELERUI_REMOBJPROTEGIDO,
 ERR_PGMODELERUI_REDECLGRUPODESTAQUE,
 ERR_PGMODELERUI_DEFGRUPOLOCALINV,
 ERR_PGMODELERUI_DEFGRUPONAODECL,
 ERR_PGMODELERUI_DEFGRUPOSEMELEM,
 ERR_PGMODELERUI_DEFGRUPODUPLICADA,
 ERR_PGMODELERUI_GRUPODECLNAODEF,
 ERR_PGMODELERUI_REFCOLTABOBJIDXINV,
 ERR_PGMODELERUI_REFLINTABOBJIDXINV,
 ERR_PGMODELERUI_OPROBJRESERVADO,
 ERR_PGMODELERUI_CONFFUNCINVALIDAOBJ,
 ERR_PGMODELERUI_TIPOSQLINDEFREFVISAO,
 ERR_PGMODELERUI_RESTPKFKSEMCOLUNAS,
 ERR_PGMODELERUI_CONFNAOCARREGADA,
 ERR_PGMODELERUI_CONFPADRAONAORESTAURADA,
 ERR_PGMODELERUI_FALHAEXPORTACAO,

 ERR_PARSERS_SINTAXEINV,
 ERR_PARSERS_CONDICIONALINV,
 ERR_PARSERS_ATRIBUTODESC,
 ERR_PARSERS_METACHARINV,
 ERR_PARSERS_ATRIBVALORNULO,
 ERR_PARSERS_ATRIBBUFXMLVAZIO,
 ERR_PARSERS_ARQDIRNAOCARREGADO,
 ERR_PARSERS_ATRIBARQDTDVAZIO,
 ERR_PARSERS_ATRIBNOMEDTDVAZIO,
 ERR_PARSERS_LIBXMLERR,
 ERR_PARSERS_OPRARVELEMNAOALOC,
 ERR_PARSERS_ARQMODELOINV,
 ERR_PARSERS_OPRELEMNAOALOC,
 ERR_PARSERS_OPRELEMINVARVDOC,

 ERR_CONEXBD_ATRPARAMINVCONEX,
 ERR_CONEXBD_OPRCONEXNAOALOC,
 ERR_CONEXBD_CONEXSEMPARAMCONFIG,
 ERR_CONEXBD_CONEXNAOESTABELECIDA,
 ERR_CONEXBD_ATRRESSQLNAOALOC,
 ERR_CONEXBD_SGBDRESPINCOMP,
 ERR_CONEXBD_SGBDERROFATAL,
 ERR_CONEXBD_COMANDOSQLVAZIO,
 ERR_CONEXBD_REFCOLTUPLAIDXINV,
 ERR_CONEXBD_REFCOLTUPLANOMEINV,
 ERR_CONEXBD_REFTUPLANAOEXISTE,
 ERR_CONEXBD_CMDSQLNAOEXECUTADO
};
//***********************************************************
class Excecao {
 private:
  /* Armazena outras execeções antes do disparo da exceção this.
     Esta estrutura pode ser usada para simular um stack trace,
     para melhorar o debug */
  deque<Excecao> excecoes;

  //Armazena as mensagens de erros e os códigos (nomes dos erros) em formato string
  static QString mensagens[QTD_ERROS][2];

  static const unsigned CODIGO_ERRO=0,
                        MENSAGEM_ERRO=1;

  TipoErro tipo_erro;
  QString msg_erro,
         /* Armazena o nome da classe e método de onde foi
            disparada a exceção. Para que isso seja possí­vel, no momento
            da instanciação desta classe a macro do G++ __PRETTY_FUNCTION__
            deve ser passada. Essa macro contém o formato [RETORNO][CLASSE]::[METODO][PARAMS] */
         local,
         //Arquivo de onde foi gerada a exceção (Macro __FILE__)
         arquivo,

         /* Informações adicionais (de preenchimento opcinal) pode armazer qualquer outro
            tipo de informação interessante à tentativa de resolução do erro */
         info_adicional;

      //Linha do arquivo de onde foi gerada a exceção (Macro __LINE__)
  int linha;

  //Configura os atributos básicos da exceção
  void configurarExcecao(const QString &msg, TipoErro tipo_erro, const QString &local, const QString &arquivo, int linha, const QString &info_adicional);

  //Adiciona um exceção na lista de exceções
  void adicionarExecao(Excecao &execao);

 public:
  Excecao(void);
  Excecao(const QString &msg, const QString &local, const QString &arquivo, int linha, Excecao *excecao=NULL, const QString &info_adicional="");
  Excecao(const QString &msg, TipoErro tipo_erro, const QString &local, const QString &arquivo, int linha, Excecao *excecao=NULL, const QString &info_adicional="");
  Excecao(TipoErro tipo_erro, const QString &local, const QString &arquivo, int linha, Excecao *excecao=NULL, const QString &info_adicional="");
  Excecao(TipoErro tipo_erro, const QString &local, const QString &arquivo, int linha, vector<Excecao> &excecoes, const QString &info_adicional="");
  ~Excecao(void){}
  QString obterMensagemErro(void);
  static QString obterMensagemErro(TipoErro tipo_erro);
  static QString obterNomeErro(TipoErro tipo_erro);
  QString obterLocal(void);
  QString obterArquivo(void);
  QString obterLinha(void);
  TipoErro obterTipoErro(void);
  QString obterInfoAdicional(void);
  void obterListaExcecoes(deque<Excecao> &lista);
};
//***********************************************************
#endif