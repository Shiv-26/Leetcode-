class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Build the adjacency list and populate indegrees
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }
        
        // Step 2: Push all courses with 0 prerequisites into the queue
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Step 3: Process the queue
        int completedCourses = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            completedCourses++;
            
            // Reduce the indegree for all neighboring dependent courses
            for (int neighbor : adj[curr]) {
                indegree[neighbor]--;
                // If all prerequisites are cleared, add to queue
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // Step 4: If we processed all courses, there is no cycle
        return completedCourses == numCourses;
    }
};