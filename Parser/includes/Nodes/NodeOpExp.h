/*
 * NodeOpExp.h
 *
 *  Created on: 08.01.2017
 *      Author: yannick
 */

#ifndef PARSER_INCLUDES_NODES_NODEOPEXP_H_
#define PARSER_INCLUDES_NODES_NODEOPEXP_H_

#include "NodeOp.h"
#include "NodeExp.h"

class NodeExp;

class NodeOpExp: public Node {
private:
	NodeOp* op;
	NodeExp* exp;

public:
	~NodeOpExp() {
		delete this->op;
		delete this->exp;
	}

	void addNode(NodeOp* op) {
		this->op = op;
	}

	void addNode(NodeExp* exp) {
		this->exp = exp;
	}

	void accept(ParseTreeVisitor* visitor) {
		visitor->visitNode(this);
	}

	NodeOp* getOp() {
		return this->op;
	}

	NodeExp* getExp() {
		return this->exp;
	}
};

#endif /* PARSER_INCLUDES_NODES_NODEOPEXP_H_ */
