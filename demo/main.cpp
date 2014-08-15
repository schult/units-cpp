#include <QApplication>
#include <QTranslator>
#include <QLocale>

#include <iostream>

#include "UnitDefinitions.h"

int main( int argc, char **argv )
{
    QApplication app( argc, argv );

    QLocale locale( "es_AR" );
    QLocale::setDefault( locale );

    QTranslator translator;
    //translator.load( locale, "units", ".", "demo" );
    // directory: QLibraryInfo::location( QLibraryInfo::TranslationsPath )
    (void)translator.load( "demo/units_es-Ar.qm" );
    app.installTranslator( &translator );

    const QString mm_symbol = Units::Translate( Units::millimeters );
    std::cout << mm_symbol.toUtf8().constData() << std::endl;

    return app.exec();
}

