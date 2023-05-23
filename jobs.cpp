void scheduleJobs(vector<pair<int, int>>& jobs, int timeSlice) {
	queue<pair<int, int>> jobQueue;

	// Populate the job queue
	for (int i = 0; i < jobs.size(); i++) {
		jobQueue.push(jobs[i]);
	}
	cout << endl;

	while (!jobQueue.empty()) {
		int currentJobId = jobQueue.front().first;
		int currentJobExecution = jobQueue.front().second;
		jobQueue.pop();

		// Execute the job for the given time slice
		if (currentJobExecution > timeSlice) {
			currentJobExecution -= timeSlice;
			cout << "Executing Job " << currentJobId << " for " << timeSlice << " units of time." << endl;
			jobQueue.push({currentJobId, currentJobExecution}); // Move the job to the end of the queue
		} else {
			cout << "Executing Job " << currentJobId << " for " << currentJobExecution << " units of time." << endl;
		}
	}
}

int main() {
	//init_code();
	int n;
	cin >> n;
	vector<pair<int, int>> jobs;
	for (int i = 0; i < n; i++) {
		int id, executionTime;
		cin >> id >> executionTime;
		jobs.push_back({id, executionTime});
	}

	int timeSlice = 4;
	scheduleJobs(jobs, timeSlice);

	return 0;
}
