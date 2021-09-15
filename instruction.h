#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "turtlescene.h"
#include "turtlelang.h"

// Class instanced are used to execute parsed Instructions
class Instruction
{
public:
    virtual ~Instruction() = default;
    virtual void executeInstruction(TurtleScene* turtleScene) = 0;

protected:
    InstructionType type;
};

class PenInstruction : public Instruction
{
public:
    PenInstruction(InstructionType type);
    ~PenInstruction() {};
    void executeInstruction(TurtleScene* turtleScene);
};

class MoveInstruction : public Instruction
{
public:
    MoveInstruction(InstructionType type, int distance);
    ~MoveInstruction() {};
    void executeInstruction(TurtleScene* scene);

private:
    int unitsMoved;
};

#endif
