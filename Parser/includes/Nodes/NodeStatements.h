/*
 * NodeStatements.h
 *
 *  Created on: 08.01.2017
 *      Author: yannick
 */

#ifndef PARSER_INCLUDES_NODES_NODESTATEMENTS_H_
#define PARSER_INCLUDES_NODES_NODESTATEMENTS_H_

#include "NodeStatement.h"

class NodeStatements: public Node {
private:
	NodeStatement* statement;
	NodeStatements* statements;

public:

	~NodeStatements() {
		delete this->statement;
		delete this->statements;
	}

	void addNode(NodeStatement* statement) {
		this->statement = statement;
	}

	void addNode(NodeStatements* statements) {
			this->statements = statements;
	}

	void accept(ParseTreeVisitor* visitor) {
		visitor->visitNode(this);
	}

	NodeStatement* getStatement() {
		return this->statement;
	}

	NodeStatements* getStatements() {
		return this->statements;
	}
};

#endif /* PARSER_INCLUDES_NODES_NODESTATEMENTS_H_ */
