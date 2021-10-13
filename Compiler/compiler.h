#ifndef COMPILER_H
#define COMPILER_H

#include "statement.h"

#include <memory>
#include <string>

std::shared_ptr<Turtle::Statement> compile(const std::string& input);

#endif
