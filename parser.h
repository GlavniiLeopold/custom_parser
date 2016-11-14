#ifndef parser_H
#define parser_H

#include <QVector>
#include <QString>
#include <iostream>

struct Connection
{
    Connection(int o, QString r, int f1, int f2){rule = r; old = o; from1 = f1; from2 = f2;}
    QString rule;
    int old;
    int from1;
    int from2;
};
struct {
        bool operator()(Connection* a, Connection* b)
        {
            return a->old < b->old;
        }
    } customSort;

struct Rule
{
    Rule(QString r, QString f)
    {
        result = r;
        from = f.split(' ');
        info = f.toStdString();
        size = from.size();
    }
    QString result;
    QStringList from;
    std::string info;
    int size;
};

class Parser
{
public:
    Parser();

    void print_tree_nodes();
    void add_rule(QString r, QString f);
    void parse(QString data);

private:
    QVector<QString> punctuation;
    QVector<QString> keywords;
    QVector<QString> op;
    QVector<Rule*> rules;
    QVector<QStringList*> matrix;
    QVector<Connection*> tree;

    void analyse_synt(QStringList &words);
    QString check_rule(QString rule0, QString rule1);
    QString check_rule(QString rule0);
    void get_diagonals(int pos, int size);
    void analyse_lex(QStringList &words);
    void divide(QStringList &words, int pos);
    inline bool is_num(QChar n);
    inline int is_op(QChar a, QChar b);
    inline void push_back(QVector<QString> &v, QString s);
};

#endif // parser_H
