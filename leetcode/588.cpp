// 588. Design In-Memory File System
class Node{
public:
    string dirname;
    vector<Node*> ch;
    unordered_map<string, string> files;
    set<string> filenames;
    
    Node(string name){
        dirname = name;
    }

    void adddir(Node *ch_node){
        if( ch_node == NULL ) return;
        ch.push_back( ch_node );
        filenames.insert( ch_node->dirname );
    }
    
    void addfile(string &filename, string &content){
        files[filename] += content;
        filenames.insert(filename);
    }
    
    string readfile(string &filename){
        assert( files.count(filename) == 1 );
        return files[filename];
    }
};

class FileSystem {
public:
    FileSystem() {
        root = new Node("/");
        jump["/"] = root;
    }
    
    vector<string> ls(string path) {
        Node *dir = NULL;
        path = (path == "/") ? path : path+"/";
        if( jump.count(path) == 1 )
            dir = jump[path];
        
        if(dir == NULL){
            size_t last_end = path.rfind("/"); 
            size_t end = path.rfind("/", last_end-1);
            string dirname = path.substr(end+1,last_end-(end+1)); // [end+1, last_end)
            string subpath = path.substr(0, end+1); // [0, end]
            
            if( jump.count(subpath) == 1 
               && jump[subpath]->filenames.count(dirname) == 1){
                return vector<string>{dirname};
            }
            return vector<string>();
        }
        else{
            vector<string> res;
            for(auto s: dir->filenames)
                res.push_back( s );
            return res;
        }
    }
    
    void mkdir(string path) {
        assert(path != "/");
        
        path += "/";
        size_t last_end = path.rfind("/"); 
        size_t end = path.rfind("/", last_end-1);
        string dirname = path.substr(end+1,last_end-(end+1)); // [end+1, last_end)
        string subpath = path.substr(0, end+1); // [0, end]
        
        Node *dir = NULL;
        Node *head = new_node(subpath, dirname);
        while( dir == NULL ){
            if( jump.count(subpath) == 1 ){
                dir = jump[subpath];
                dir->adddir(head);
                return;
            }
            else{
                // create parent
                last_end = end;
                end = path.rfind("/", last_end-1);
                dirname = path.substr(end+1,last_end-(end+1)); // [end+1, last_end)
                subpath = path.substr(0, end+1); // [0, end]
                Node *parent = new_node(subpath,dirname);
                
                parent->adddir(head);
                head = parent;
            }
        }
    }
    
    Node *new_node(string &subpath, string &dirname){
        Node *res = new Node(dirname);
        jump[subpath+dirname+"/"] = res;
        return res;
    }
    
    void addContentToFile(string path, string content) {
        path += "/";
        size_t last_end = path.rfind("/"); 
        size_t end = path.rfind("/", last_end-1);
        string filename = path.substr(end+1,last_end-(end+1)); // [end+1, last_end)
        string subpath = path.substr(0, end+1); // [0, end]
        
        assert( jump.count(subpath) == 1 );
        
        //addfile(jump[subpath], subpath, filename, content);
        jump[subpath]->addfile( filename, content );
    }
    
    string readContentFromFile(string path) {
        path += "/";
        size_t last_end = path.rfind("/"); 
        size_t end = path.rfind("/", last_end-1);
        string filename = path.substr(end+1,last_end-(end+1)); // [end+1, last_end)
        string subpath = path.substr(0, end+1); // [0, end]
        
        assert( jump.count(subpath) == 1 );
        
        return jump[subpath]->readfile(filename);
    }
    
private:
    Node *root;
    unordered_map<string, Node*> jump;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
