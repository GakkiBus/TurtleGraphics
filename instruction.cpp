#include "instruction.h"
#include "turtlelang.h"
#include "turtlescene.h"
#include "symbolic_table.h"

#include <string>

SymbolicTable Instruction::symbolicTable{};

void Instruction::resetTable()
{
    symbolicTable = SymbolicTable{};
}

InstructionType Instruction::getType()
{
    return type;
}

void HaltInstruction::executeInstruction(TurtleScene*)
{
    resetTable();
}

void PenInstruction::executeInstruction(TurtleScene* turtleScene)
{
    switch (type)
    {
        case InstructionType::PEN_DOWN:
            turtleScene->penDown();
            break;
        case InstructionType::PEN_UP:
            turtleScene->penUp();
            break;
        default:
            exit(1);
    }
}

void MoveInstruction::executeInstruction(TurtleScene* turtleScene)
{
    int unitsMoved{(!argVarname.empty()) ? symbolicTable.lookup(argVarname) : this->unitsMoved};
    switch (type)
    {
        case InstructionType::MOVE_NORTH:
            turtleScene->movePenY(-unitsMoved);
            break;
        case InstructionType::MOVE_EAST:
            turtleScene->movePenX(unitsMoved);
            break;
        case InstructionType::MOVE_SOUTH:
            turtleScene->movePenY(unitsMoved);
            break;
        case InstructionType::MOVE_WEST:
            turtleScene->movePenX(-unitsMoved);
            break;
        case InstructionType::ROTATE:
            turtleScene->setRotationAngle(unitsMoved);
            break;
        default:
            exit(1);
    }
}

void VarInstruction::executeInstruction(TurtleScene*)
{
    int value{(!argVarname.empty()) ? symbolicTable.lookup(argVarname) : this->value};
    switch (type)
    {
        case InstructionType::VAR_INC:
        {
            int oldValue{symbolicTable.lookup(varname)};
            symbolicTable.update(varname, oldValue + value);
            break;
        }
        case InstructionType::VAR_DEC:
        {
            int oldValue{symbolicTable.lookup(varname)};
            symbolicTable.update(varname, oldValue - value);
            break;
        }
        case InstructionType::VAR_SET:
            symbolicTable.update(varname, value);
            break;
        default:
            exit(1);
    }
}
