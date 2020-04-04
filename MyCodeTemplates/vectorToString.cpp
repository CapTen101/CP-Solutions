string vectorToString(vector<long long> vec)
{
    ostringstream vts;
    if (!vec.empty())
    {
        // Convert all but the last element to avoid a trailing ","
        copy(vec.begin(), vec.end() - 1, ostream_iterator<int>(vts));

        // Now add the last element with no delimiter
        vts << vec.back();

        return vts.str();
    }
}