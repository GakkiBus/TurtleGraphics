#ifndef TURTLE_STATEMENT_H
#define TURTLE_STATEMENT_H

#include "statement.h"
#include "symbol_table.h"
#include "rational.h"

#include <string>

class TurtleScene;

class PenUpStatement : public Turtle::Statement
{
private:
    TurtleScene* scene;

public:
    PenUpStatement(TurtleScene* s) : scene{s} {}
    ~PenUpStatement() {};
    void execute(SymbolTable& table);
};

class PenDownStatement : public Turtle::Statement
{
private:
    TurtleScene* scene;

public:
    PenDownStatement(TurtleScene* s) : scene{s} {}
    ~PenDownStatement() {};
    void execute(SymbolTable& table);
};

class MoveStatement : public Turtle::Statement
{
private:
    TurtleScene* scene;

public:
    MoveStatement(TurtleScene* s) : scene{s} {}
    ~MoveStatement() {};
    void execute(SymbolTable& table);
};

class RotateStatement : public Turtle::Statement
{
private:
    TurtleScene* scene;

public:
    RotateStatement(TurtleScene* s) : scene{s} {}
    ~RotateStatement() {};
    void execute(SymbolTable& table);
};

#endif
