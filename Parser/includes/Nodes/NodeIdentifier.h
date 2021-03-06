/*
 * NodeIdentifier.h
 *
 *  Created on: 08.01.2017
 *      Author: yannick
 */

#ifndef PARSER_INCLUDES_NODES_NODEIDENTIFIER_H_
#define PARSER_INCLUDES_NODES_NODEIDENTIFIER_H_

#include "../../../Symboltable/includes/Information.h"
#include "../../../Scanner/includes/Token.h"

class NodeIdentifier: public Node {
private:
	Information* information;
	Token* token;

public:
	NodeIdentifier(Token* token) {
		this->token = token;
	}

	void addInformation(Information* information) {
		this->information = information;
	}

	void accept(ParseTreeVisitor* visitor) {
		visitor->visitNode(this);
	}

	Information* getInformation() {
		return this->information;
	}

	virtual void setType(Node::NodeType type) {
		information->setType(type);
	}

	virtual Node::NodeType getType() {
		return information->getType();
	}

	unsigned int getLine() {
		return this->token->getLine();
	}

	unsigned int getColumn() {
		return this->token->getColumn();
	}
};


#endif /* PARSER_INCLUDES_NODES_NODEIDENTIFIER_H_ */
