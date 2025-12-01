Node* bt_re(std::list<std::string>& ls){
    if(ls.front() == "#"){
        ls.pop_front();
        return nullptr;
    }
    auto c = ls.front();
    int val = stoi(c); 
    Node * p = new Node();
    p->val = val;
    ls.pop_front();
    Node* l = bt_re(ls);
    Node* r = bt_re(ls);
    p->left = l;
    p->right = r;
    return p;
}

Node* build_tree(){
    std::string str = "11,12,#,14,#,#,13,#,#";
   auto vw = str | std::ranges::views::split(',');
    std::list<std::string> ls;
   for(auto e : vw){
    std::string s(std::from_range, e);
    ls.push_back(s);
   }
   
   return bt_re(ls);
}