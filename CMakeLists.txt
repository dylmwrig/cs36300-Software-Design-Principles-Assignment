cmake_minimum_required(VERSION 3.6)
project(calculator2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Add_Node.cpp Array.cpp Array_Iterator.cpp Binary_Expr_Node.cpp Div_Node.cpp driver.cpp Expr_Node.cpp Modulus_Node.cpp Mult_Node.cpp Num_Node.cpp Open_Paren_Node.cpp Stack.cpp Stack_Expr_Command_Factory.cpp Sub_Node.cpp Variable_Command.cpp Unary_Expr_Node.cpp Unary_Expr_Node.h Eval_Expr_Tree.cpp Eval_Expr_Tree.h Expr_Node_Visitor.cpp Expr_Node_Visitor.h Expr_Builder.cpp Expr_Builder.h Expr_Tree_Builder.cpp Expr_Tree_Builder.h Expr_Tree.cpp Expr_Tree.h Close_Paren_Node.cpp Close_Paren_Node.h Calculator.cpp Calculator.h)
add_executable(calculator2 ${SOURCE_FILES})