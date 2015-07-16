class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode*> track;
        return cloneGraph(node, track);
    }
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode *>& track)
    {
        if(!node) return NULL;
        if(track.count(node->label)) return track[node->label];
        
        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
        new_node->neighbors.resize(node->neighbors.size());
        track[node->label] = new_node;
        
        for(int i = 0; i < node->neighbors.size(); i++)
        {
            new_node->neighbors[i] = cloneGraph(node->neighbors[i], track);
        }
        return new_node;
    }
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode*> track;
        return cloneGraph(node, track);
    }
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode *>& track)
    {
        if(!node) return NULL;
        if(track.count(node->label)) return track[node->label];
        
        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
//        new_node->neighbors.resize(node->neighbors.size());
        track[node->label] = new_node;
        
        for(int i = 0; i < node->neighbors.size(); i++)
        {
            new_node->neighbors.push_back(cloneGraph(node->neighbors[i], track));
        }
        return new_node;
    }
};
