#include <iostream>
#include <vector>
#include <thread>
#include <numeric>
#include <chrono>

int sumVectorSingleThread(const std::vector<int>& vec)
{
    int sum = 0;
    for (int num : vec)
    {
        sum += num;
    }
    return sum;
}

//int sumVectorMultiThread(const std::vector<int>& vec, int numThreads)
//{
//    int vecSize = vec.size();
//    int subVecSize = vecSize / numThreads;
//    std::vector<int> partialSums(numThreads);
//
//    std::vector<std::thread> threads;
//    for (int i = 0; i < numThreads; ++i)
//    {
//        int start = i * subVecSize;
//        int end = (i == numThreads - 1) ? vecSize : (i + 1) * subVecSize;
//        threads.emplace_back([start, end, &vec, &partialSums, i]()
//            {
//                partialSums[i] = std::accumulate(vec.begin() + start, vec.begin() + end, 0);
//            });
//    }
//
//    for (auto& thread : threads)
//    {
//        thread.join();
//    }
//
//    int result = std::accumulate(partialSums.begin(), partialSums.end(), 0);
//    return result;
//}

int main()
{
    std::vector<int> vecSizes = { 10000, 50000, 100000 };

    int numThreads = 500;
    int numTests = 5;

    std::cout << "Vector Size\tThreads\tTime (s)\tBoost" << std::endl;

    for (int vecSize : vecSizes)
    {
        for (int i = 0; i < numTests; ++i)
        {
            std::vector<int> testVec(vecSize, 1);

            auto startSingleThread = std::chrono::high_resolution_clock::now();
            int sumSingleThread = sumVectorSingleThread(testVec);
            auto endSingleThread = std::chrono::high_resolution_clock::now();

            auto startMultiThread = std::chrono::high_resolution_clock::now();
            //int sumMultiThread = sumVectorMultiThread(testVec, numThreads);
            auto endMultiThread = std::chrono::high_resolution_clock::now();

            double timeSingleThread = std::chrono::duration_cast<std::chrono::milliseconds>(endSingleThread - startSingleThread).count() / 1000.0;
            double timeMultiThread = std::chrono::duration_cast<std::chrono::milliseconds>(endMultiThread - startMultiThread).count() / 1000.0;

            double boostFactor = timeSingleThread / timeMultiThread;

            std::cout << vecSize << "\t" << numThreads << "\t" << timeMultiThread << "\t" << boostFactor << std::endl;
        }
    }

    return 0;
}
