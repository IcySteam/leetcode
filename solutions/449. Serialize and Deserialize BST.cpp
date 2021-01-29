                        allNull = false;
                        output.append(to_string(front->left->val) + ",");
                        myQueue.push(front->left);
                    }
                    if (front->right == nullptr) {
                        output.append("n,");
                        myQueue.push(nullptr);
                    }
                    else {
                        allNull = false;
                        output.append(to_string(front->right->val) + ",");
                        myQueue.push(front->right);
                    }
                }
                else {
                    output.append("n,");
                    output.append("n,");
                    myQueue.push(nullptr);
                    myQueue.push(nullptr);
                }
                myQueue.pop();
            }
            if (allNull) {break;}
        }
        int trimIndex;
        for (int i = output.size() - 1; i >= 0; i--) {
            if (output[i] != ',' && output[i] != 'n') {
                trimIndex = i;
                break;
            }
        }
        output = output.substr(0, trimIndex + 2);
        cout << output << endl;
        //vector<int> outputVec = str2vec(output);
        // for (auto ele : outputVec) {cout << ele << " ";}
        // cout << endl;
        return output;
    }
​
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") {return nullptr;}
        vector<int> dataVec = str2vec(data);
        TreeNode* output = new TreeNode(dataVec[0]); // cbb to free
        vector<TreeNode*> nodes;
        nodes.push_back(output);
        int currentDepth = 1;
        int depth = getDepthFromSize(dataVec.size());
        while (currentDepth < depth) {
            int start = getIndexFromDepth(currentDepth);
            int end;
            int end1 = getIndexFromDepth(currentDepth + 1);
            if (end1 > dataVec.size()) {end = dataVec.size();}
            else {end = end1;}
            for (int i = start; i < end; i++) {
                if (dataVec[i] == -1) {nodes.push_back(nullptr);}
                else {
                    TreeNode* newNode = new TreeNode(dataVec[i]);
                    nodes.push_back(newNode);
                    TreeNode* parent = nodes[(i - 1) / 2];
                    // cout << "index: " << i << endl;
                    // if (parent == nullptr) {cout << "NULL!\n";}
                    // else {cout << "val: " << parent->val << endl;}
                    if (i % 2 == 0) {parent->right = newNode;}
                    else {parent->left = newNode;}
                }
            }
            currentDepth++;
        }
        return output;
    }
    
