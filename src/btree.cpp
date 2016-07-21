/*
 * Author: Daniel R Madison
 * Copyright (C) 2016
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include "../includes/btree.h"

using namespace std;
BinaryTree::BinaryTree() {}

BinaryTree::~BinaryTree() {
	this->destroyTree(this->root);
}

void BinaryTree::insert(int key) {
	if (this->root == NULL)
		insert(key, this->root);
	else {
		root = new Node;
		root->key;
		root->left = NULL;
		root->right = NULL;
	}
}

void BinaryTree::destroyTree(Node * n) {
	if (n != NULL) {
		destroyTree(n->left);
		destroyTree(n->right);
		delete n;
	}
}

void BinaryTree::insert(int k, Node * n) {
	if (k < n->key) {
		if (n->left != NULL) {
			insert(k, n->left);
		} else {
			n->left = new Node;
			n->left->key = k;
			n->left->left = NULL;
			n->left->right = NULL;
		}
	} else {
		if (n->right != NULL) {
			insert(k, n->right);
		} else {
			n->right = new Node;
			n->right->key = k;
			n->right->left = NULL;
			n->right->right = NULL;
		}
	}
}

void BinaryTree::insert(int k) {
	if (this->root != NULL) {
		insert(k, root);
	} else {
		root = new Node;
		root->key = k;
		root->left = NULL;
		root->right = NULL;
	}
}

BreadthFirstSearch::BreadthFirstSearch(BinaryTree* t, int k) {
	this->search(t, k);
}

BreadthFirstSearch::~BreadthFirstSearch() {}

Node* BreadthFirstSearch::search(Node* n, int k) {
	return 0;
}

DepthFirstSearch::DepthFirstSearch(BinaryTree* t, int k) {
	this->search(t->getRoot(), k);
}

DepthFirstSearch::~DepthFirstSearch() {}

Node * DepthFirstSearch::search(Node* n, int k) {
	if (n == NULL)
		return NULL;
	else if (n->key == k)
		return n;

	if (k < n->key)
		return this->search(n->left, k);
	else
		return this->search(n->right, k);
}
