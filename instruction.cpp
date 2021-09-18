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


HaltInstruction::HaltInstruction(InstructionType type)
{
    this->type = type;
}

void HaltInstruction::executeInstruction(TurtleScene* turtleScene)
{
    resetState();
}


PenInstruction::PenInstruction(InstructionType type)
{
    this->type = type;
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


MoveInstruction::MoveInstruction(InstructionType type, int unitsMoved)
{
    this->type = type;
    this->unitsMoved = unitsMoved;
}

void MoveInstruction::executeInstruction(TurtleScene* turtleScene)
{
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


VarInstruction::VarInstruction(InstructionType type, std::string varname, int value)
{
    this->type = type;
    this->varname = varname;
    this->value = value;
}

void VarInstruction::executeInstruction(TurtleScene* turtleScene)
{
    switch (type)
    {
        case VAR_INC:
        {
            int oldValue{lookupState(varname)};
            updateState(varname, oldValue + 1);
            break;
        }
        case VAR_DEC:
        {
            int oldValue{lookupState(varname)};
            updateState(varname, oldValue - 1);
            break;
        }
        case VAR_SET:
            updateState(varname, value);
            break;
    }
}
