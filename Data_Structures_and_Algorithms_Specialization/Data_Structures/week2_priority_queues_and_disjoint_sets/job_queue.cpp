
#include <bits/stdc++.h> 
using namespace std;

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  struct compareFn{
      bool operator()(vector<long long> a, vector<long long> b){
      if(a[1]==b[1])
        return(a[0]>b[0]);
      return(a[1]>b[1]);
    }  
  };
  

  void AssignJobsNew() {
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());

    priority_queue <vector<long long>, vector<vector<long long>>, compareFn> free_workers;
    for(long long i=0; i<num_workers_; i++){
      free_workers.push({i,0});
    }

    vector<long long> worker, tem1;
    long long t=0;

    for(long long i=0; i<jobs_.size(); i++){
      worker = free_workers.top();
      free_workers.pop();
      if(worker[1]==0){
        free_workers.push(vector<long long> {worker[0], t+jobs_[i]});
        assigned_workers_[i] = worker[0];
        start_times_[i] = t;
      }
      else{
        if(t < worker[1])
          t = worker[1];
        free_workers.push(vector<long long> {worker[0], t+jobs_[i]});
        assigned_workers_[i] = worker[0];
        start_times_[i] = worker[1];
      }
    }
  }



  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    vector<long long> next_free_time(num_workers_, 0);
    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      int next_worker = 0;
      for (int j = 0; j < num_workers_; ++j) {
        if (next_free_time[j] < next_free_time[next_worker])
          next_worker = j;
      }
      assigned_workers_[i] = next_worker;
      start_times_[i] = next_free_time[next_worker];
      next_free_time[next_worker] += duration;
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobsNew();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
