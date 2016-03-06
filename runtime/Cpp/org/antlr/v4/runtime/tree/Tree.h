﻿#pragma once
#include <string>

/*
 * [The "BSD license"]
 *  Copyright (c) 2013 Terence Parr
 *  Copyright (c) 2013 Dan McLaughlin
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. The name of the author may not be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 *  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 *  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 *  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 *  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 *  THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

namespace org {
    namespace antlr {
        namespace v4 {
            namespace runtime {
                namespace tree {
                    /// <summary>
                    /// The basic notion of a tree has a parent, a payload, and a list of children.
                    ///  It is the most abstract interface for all the trees used by ANTLR.
                    /// </summary>
                    class Tree {
                        /// <summary>
                        /// The parent of this node. If the return value is null, then this
                        ///  node is the root of the tree.
                        /// </summary>
                    public:
                        virtual Tree *getParent() = 0;

                        /// <summary>
                        /// This method returns whatever object represents the data at this note. For
                        /// example, for parse trees, the payload can be a <seealso cref="Token"/> representing
                        /// a leaf node or a <seealso cref="RuleContext"/> object representing a rule
                        /// invocation. For abstract syntax trees (ASTs), this is a <seealso cref="Token"/>
                        /// object.
                        /// </summary>
                        virtual void *getPayload() = 0;

                        /// <summary>
                        /// If there are children, get the {@code i}th value indexed from 0. </summary>
                        virtual Tree *getChild(int i) = 0;

                        /// <summary>
                        /// How many children are there? If there is none, then this
                        ///  node represents a leaf node.
                        /// </summary>
                        virtual int getChildCount() = 0;

                        /// <summary>
                        /// Print out a whole tree, not just a node, in LISP format
                        ///  {@code (root child1 .. childN)}. Print just a node if this is a leaf.
                        /// </summary>
                        virtual std::wstring toStringTree() = 0;

                        virtual std::wstring toString() = 0;
                    };

                }
            }
        }
    }
}
