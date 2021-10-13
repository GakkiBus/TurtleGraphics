#include "compiler.h"
#include "statement.h"
#include "lexer.h"
#include "parser.h"
#include "code_generation.h"

#include <memory>
#include <string>

std::shared_ptr<Turtle::Statement> compile(const std::string& input)
{
    Lexer lexer{input};
    Parser parser{&lexer};
    return generate(parser.parse());
}
