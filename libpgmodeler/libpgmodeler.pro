include(../pgmodeler.pro)

CONFIG += qt warn_on uitools uic4
QT = core gui qt3support
TEMPLATE = lib
TARGET = pgmodeler
DESTDIR = ../build/lib
DEPENDPATH = ". src obj"
OBJECTS_DIR = obj

LIBS += $$DESTDIR/$$LIBUTIL \
        $$DESTDIR/$$LIBPARSERS

HEADERS += $$PWD/src/caixatexto.h \
           $$PWD/src/conversaotipo.h \
           $$PWD/src/funcao.h \
           $$PWD/src/linguagem.h \
           $$PWD/src/operador.h \
           $$PWD/src/relacionamentobase.h \
           $$PWD/src/tabelabase.h \
           $$PWD/src/coluna.h \
           $$PWD/src/dominio.h \
           $$PWD/src/funcaoagregacao.h \
           $$PWD/src/modelobd.h \
           $$PWD/src/papel.h \
           $$PWD/src/restricao.h \
           $$PWD/src/tipo.h \
           $$PWD/src/espacotabela.h \
           $$PWD/src/gatilho.h \
           $$PWD/src/objetobase.h \
           $$PWD/src/regra.h \
           $$PWD/src/sequencia.h \
           $$PWD/src/tipospgsql.h \
           $$PWD/src/conversaocodificacao.h \
           $$PWD/src/esquema.h \
           $$PWD/src/elementoindice.h \
           $$PWD/src/indice.h \
           $$PWD/src/objetograficobase.h \
           $$PWD/src/relacionamento.h \
           $$PWD/src/tabela.h \
           $$PWD/src/visao.h \
           $$PWD/src/familiaoperadores.h \
           $$PWD/src/elemclasseoperadores.h \
           $$PWD/src/classeoperadores.h \
           $$PWD/src/listaoperacoes.h \
           $$PWD/src/objetotabela.h \
           $$PWD/src/referencia.h \
           $$PWD/src/permissao.h

SOURCES +=  $$PWD/src/caixatexto.cpp \
            $$PWD/src/dominio.cpp \
            $$PWD/src/gatilho.cpp \
            $$PWD/src/objetograficobase.cpp \
            $$PWD/src/relacionamentobase.cpp \
            $$PWD/src/tipo.cpp \
            $$PWD/src/coluna.cpp \
            $$PWD/src/espacotabela.cpp \
            $$PWD/src/elementoindice.cpp \
            $$PWD/src/indice.cpp \
            $$PWD/src/operador.cpp \
            $$PWD/src/restricao.cpp \
            $$PWD/src/tipospgsql.cpp \
            $$PWD/src/esquema.cpp \
            $$PWD/src/linguagem.cpp \
            $$PWD/src/papel.cpp \
            $$PWD/src/sequencia.cpp \
            $$PWD/src/visao.cpp \
            $$PWD/src/conversaocodificacao.cpp \
            $$PWD/src/funcao.cpp \
            $$PWD/src/modelobd.cpp \
            $$PWD/src/regra.cpp \
            $$PWD/src/tabela.cpp \
            $$PWD/src/conversaotipo.cpp \
            $$PWD/src/funcaoagregacao.cpp \
            $$PWD/src/objetobase.cpp \
            $$PWD/src/relacionamento.cpp \
            $$PWD/src/tabelabase.cpp \
            $$PWD/src/familiaoperadores.cpp \
            $$PWD/src/elemclasseoperadores.cpp \
            $$PWD/src/classeoperadores.cpp \
            $$PWD/src/listaoperacoes.cpp \
            $$PWD/src/objetotabela.cpp \
            $$PWD/src/referencia.cpp \
            $$PWD/src/permissao.cpp
