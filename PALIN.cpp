#include <bits/stdc++.h>
using namespace std;

int main(){
  // 1. Tái định hướng luồng nhập xuất chuẩn vào các file tương ứng
    freopen("PALIN.inp", "r", stdin);
    freopen("PALIN.out", "w", stdout);

    // Tối ưu hóa tốc độ đọc ghi của luồng cin/cout
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // 2. Nhập dữ liệu từ file thông qua lệnh cin thông thường
    string s;
    cin >> s;
    int n = s.length();
    //3. Tạo xâu đảo ngược
    string s_rev = s;
    reverse(s_rev.begin(), s_rev.end());

    // 4. Khởi tạo bảng Quy hoạch động (DP table)
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // 5. Tiến hành điền bảng DP
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == s_rev[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // 6. Tính toán kết quả
    int lps_length = dp[n][n];
    int result = 2 * n - lps_length;

    // 7. Xuất kết quả ra file thông qua lệnh cout thông thường
    cout << result;
  return 0;
}
