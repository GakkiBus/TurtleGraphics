#include "turtle_statement.h"
#include "statement.h"
#include "symbol_table.h"
#include "rational.h"
#include "turtlescene.h"

#include <iostream>

void PenUpStatement::execute(SymbolTable&)
{
    scene->penUp();
}

void PenDownStatement::execute(SymbolTable&)
{
    scene->penDown();
}

void MoveStatement::execute(SymbolTable& table)
{
    tableEntry* search{table.lookup("x")};
    if (search != nullptr && !(search->isProcedure)) {
        scene->movePenX((search->value).toDouble());
    } else {
        std::cerr << "Error looking up variable '" << "x" << "'\n";
        exit(1);
    }
}

void RotateStatement::execute(SymbolTable& table)
{
    tableEntry* search{table.lookup("x")};
    if (search != nullptr && !(search->isProcedure)) {
        scene->setRotationAngle(search->value.toDouble());
    } else {
        std::cerr << "Error looking up variable '" << "x" << "'\n";
        exit(1);
    }
}
