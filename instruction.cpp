#include "instruction.h"
#include "turtlelang.h"
#include "turtlescene.h"

#include <map>
#include <string>

std::map<std::string, int> Instruction::state{};

void Instruction::resetState()
{
    state.clear();
}

void Instruction::updateState(std::string varname, int value)
{
    state.insert_or_assign(varname, value);
}

int Instruction::lookupState(std::string varname)
{
    auto search{state.find(varname)};
    if (search != state.end()) {
        return search->second;
    } else {
        return 0;
    }
}

InstructionType Instruction::getType()
{
    return type;
}

void HaltInstruction::executeInstruction(TurtleScene* turtleScene)
{
    resetState();
}

void PenInstruction::executeInstruction(TurtleScene* turtleScene)
{
    switch (type)
    {
        case PEN_DOWN:
            turtleScene->penDown();
            break;
        case PEN_UP:
            turtleScene->penUp();
            break;
    }
}

void MoveInstruction::executeInstruction(TurtleScene* turtleScene)
{
    int unitsMoved{(!argVarname.empty()) ? lookupState(argVarname) : this->unitsMoved};
    switch (type)
    {
        case MOVE_NORTH:
            turtleScene->movePenY(-unitsMoved);
            break;
        case MOVE_EAST:
            turtleScene->movePenX(unitsMoved);
            break;
        case MOVE_SOUTH:
            turtleScene->movePenY(unitsMoved);
            break;
        case MOVE_WEST:
            turtleScene->movePenX(-unitsMoved);
            break;
        case ROTATE:
            turtleScene->setRotationAngle(unitsMoved);
            break;
    }
}

void VarInstruction::executeInstruction(TurtleScene* turtleScene)
{
    int value{(!argVarname.empty()) ? lookupState(argVarname) : this->value};
    switch (type)
    {
        case VAR_INC:
        {
            int oldValue{lookupState(varname)};
            updateState(varname, oldValue + value);
            break;
        }
        case VAR_DEC:
        {
            int oldValue{lookupState(varname)};
            updateState(varname, oldValue - value);
            break;
        }
        case VAR_SET:
            updateState(varname, value);
            break;
    }
}
