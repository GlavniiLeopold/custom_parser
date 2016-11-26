#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include "parser.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Parser *parser = new Parser();
    //вывод через дерево tree внутри parser, реализованное через вектор

    QStringList command_line = a.arguments();
    if(command_line.size() == 1)
    {
        std::cerr << "error - 1 command line arguments needed\n";
        std::cerr << "trying to read sentences from input stream\n";
        QTextStream stream(stdin);
        while(1)
        {
            std::cout << "\nEnter you sentence \n";
            parser->parse(stream.readLine());
            parser->print_tree_nodes();
        }
    }
    else
    {
        QFile inputFile1(command_line.last());
        if (inputFile1.open(QIODevice::ReadOnly))
        {
           QString data;
           QTextStream in(&inputFile1);
           while (!in.atEnd())
           {
               data.append(in.readLine());
           }
           parser->parse(data);
           parser->print_tree_nodes();
           inputFile1.close();
        }
        else
        {
            std::cerr << "error, can't find the file at " << command_line.last().toStdString() << "\n";
            std::cerr << "trying to read sentences from input stream\n";
            QTextStream stream(stdin);
            while(1)
            {
                std::cout << "\nEnter you sentence \n";
                parser->parse(stream.readLine());
                parser->print_tree_nodes();
            }
        }
    }

    return a.exec();
}
