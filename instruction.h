#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "turtlescene.h"
#include "turtlelang.h"
#include "symbolic_table.h"

#include <string>

class Instruction
{
public:
    Instruction(InstructionType type) : type{type} {}
    virtual ~Instruction() = default;
    virtual void executeInstruction(TurtleScene* turtleScene) = 0;
    InstructionType getType();

protected:
    static SymbolicTable symbolicTable;
    InstructionType type;
    void resetTable();
};

class HaltInstruction : public Instruction
{
public:
    HaltInstruction(InstructionType type) : Instruction{type} {}
    ~HaltInstruction() {};
    void executeInstruction(TurtleScene* turtleScene);
};

class PenInstruction : public Instruction
{
public:
    PenInstruction(InstructionType type) : Instruction{type} {}
    ~PenInstruction() {};
    void executeInstruction(TurtleScene* turtleScene);
};

class MoveInstruction : public Instruction
{
public:
    MoveInstruction(InstructionType type, int unitsMoved)
        : Instruction{type}, unitsMoved{unitsMoved}, argVarname{} {}
    MoveInstruction(InstructionType type, const std::string& argVarname)
        : Instruction{type}, unitsMoved{}, argVarname{argVarname} {}
    ~MoveInstruction() {};
    void executeInstruction(TurtleScene* scene);

private:
    int unitsMoved;
    std::string argVarname;
};

class VarInstruction : public Instruction
{
public:
    VarInstruction(InstructionType type, const std::string& varname, int value)
        : Instruction{type}, varname{varname}, value{value}, argVarname{} {}
    VarInstruction(InstructionType type, const std::string& varname, const std::string& argVarname)
        : Instruction{type}, varname{varname}, value{}, argVarname{argVarname} {}
    ~VarInstruction() {};
    void executeInstruction(TurtleScene* turtleScene);

private:
    std::string varname;
    int value;
    std::string argVarname;
};

#endif
