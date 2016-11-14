#include <QCoreApplication>
#include <QTextStream>
#include "parser.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Parser *parser = new Parser();
    //вывод через дерево tree внутри parser, реализованное через вектор
    QTextStream stream(stdin);
    while(1)
    {
        std::cout << "\nEnter you sentence \n";
        parser->parse(stream.readLine());
        parser->print_tree_nodes();
    }

    return a.exec();
}
