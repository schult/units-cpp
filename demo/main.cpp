#include <QApplication>
#include <QTranslator>
#include <QLocale>

#include <iostream>

int main( int argc, char **argv )
{
    QApplication app( argc, argv );

    QLocale locale( "es_AR" );
    QLocale::setDefault( locale );

    QTranslator translator;
    //translator.load( locale, "units", ".", "src" );
    // directory: QLibraryInfo::location( QLibraryInfo::TranslationsPath )
    (void)translator.load( "src/units_es-Ar.qm" );
    app.installTranslator( &translator );

    const QString mm_symbol( app.translate( "Units", "mm" ) );
    std::cout << mm_symbol.toUtf8().constData() << std::endl;

    return app.exec();
}

