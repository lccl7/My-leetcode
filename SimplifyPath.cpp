//简化路径
//（1）“/." 表示本级路径，可直接忽略
//（2）”/.." 表示返回上一级目录，即若上一级目录若存在，连同“/.."一并删除，否则只删除/..
//（3）若去除冗余后为空，返回”/"
//（4）若包含连续“/”，删除多余的
//（5）若路径不是单个“/”，删除路径最后一个“/”
//分割字符串思想
//用“/”分割字符串，遍历每个分割部分，存入一个vector<string>
//若当前部分为"."，忽略， 若当前分割部分为空，证明有连续的"/"或是最后一个“/”，忽略
//若当前部分为“.."，若vector不空，去除vector最后一个元素
//再将vector中的string用“/”连接起来，得到结果
class Solution {
public:
    string simplifyPath(string path) {
        string res, p;
        vector<string> list;
        stringstream ss(path);
        while(getline(ss, p, '/'))
        {
            if(p.length() == 0 || p == ".")
                continue;
            if(p == "..")
            {
                if(!list.empty())
                    list.pop_back();
            }
            else
            {
                list.push_back(p);
            }
        }
        for(int i = 0; i < list.size(); i++)
        {
            res += "/" + list[i];
        }
        if(res.length() == 0) res = "/";
        return res;
    }
};
