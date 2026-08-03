void processStrings(string str1, int n) {
    // Strip trailing carriage return if present from input stream
    while (!str1.empty() && (str1.back() == '\r' || str1.back() == ' ')) {
        str1.pop_back();
    }

    string cur = str1;
    int total = sizeof(str) / sizeof(str[0]);

    for (int i = 0; i < n; i++) {
        int len = cur.length();
        int idx = (len % 2 == 1) ? (len - 1) / 2 : (len / 2 - 1);
        char mid = cur[idx];

        string next = "";
        for (int j = 0; j < total; j++) {
            if (str[j][0] == mid) {
                next = str[j];
                break;
            }
        }

        cout << next << (i == n - 1 ? "" : " ");
        cur = next;
    }
}
