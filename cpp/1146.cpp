class SnapshotArray {
public:
    SnapshotArray(int length) {
        L = length;
        snapshots.resize( L );
        arr = new int[L];
        
        
        for(int i = 0; i < L; i++)
            arr[i] = 0;
   
        for(int i = 0; i < L ; i++)
            snapshots[i][-1] = 0;
        
    }
    
    ~SnapshotArray(){
        delete[] arr;
    }
    
    void set(int index, int val) {
        if( arr[index] != val ){
            arr[index] = val;
            changed.insert(index);
        }
    }
    
    int snap() {
        
        for(int i: changed){
            snapshots[i][snap_id] = arr[i];   
        }
        
        changed.clear();
        
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        
        auto it = snapshots[index].lower_bound(snap_id);
        
        if( it == snapshots[index].end() )
            it--;
        else if( it->first != snap_id )
            it--;
        
        return it->second;
    }
    
private:
    vector<map<int, int>> snapshots; // index, val 
    unordered_set<int> changed;
    int L, snap_id = 0;
    int *arr;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
