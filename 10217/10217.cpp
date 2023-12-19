#include <iostream>
#include <vector>
#include <climits>
#include <queue>

const int INF = INT_MAX;

struct ticket
{
    int v;
    int c;
    int d;
    ticket() : v(0), c(0), d(0)
    {
    }
    ticket(const int v, const int c, const int d) : v(v), c(c), d(d)
    {
    }
    ticket(const ticket &t) : v(t.v), c(t.c), d(t.d)
    {
    }
    const ticket operator=(const ticket &t)
    {
        this->v = t.v, this->c = t.c, this->d = t.d;
        return *this;
    }

    friend std::istream &operator>>(std::istream &is, ticket &t);
};

struct cmp_ticket
{
    bool operator()(const ticket &lt, const ticket &rt)
    {
        if (lt.d == rt.d)
        {
            return lt.v < rt.v;
        }
        return lt.d > rt.d;
    }
};

std::istream &operator>>(std::istream &is, ticket &t)
{
    is >> t.v >> t.c >> t.d;
    return is;
}

void init_tickets(std::vector<std::vector<ticket>> &tickets, const int K)
{
    int u;
    ticket temp_ticket;
    for (int i = 0; i < K; ++i)
    {
        std::cin >> u >> temp_ticket;
        tickets[u].push_back(temp_ticket);
    }
    return;
}

const int solution(const std::vector<std::vector<ticket>> &tickets, const int N, const int M)
{
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(M + 1, INF));

    std::priority_queue<ticket, std::vector<ticket>, cmp_ticket> pq;

    pq.push(ticket(1, 0, 0));

    while (!pq.empty())
    {
        const ticket now_ticket(pq.top());
        pq.pop();
        if (now_ticket.d > dp[now_ticket.v][now_ticket.c])
        {
            continue;
        }

        if (now_ticket.v == N)
        {
            return now_ticket.d;
        }
        for (auto i = tickets[now_ticket.v].begin(); i != tickets[now_ticket.v].end(); ++i)
        {
            if (i->c + now_ticket.c > M)
            {
                continue;
            }
            ticket temp_ticket(now_ticket);
            temp_ticket.v = i->v;
            temp_ticket.c += i->c;
            temp_ticket.d += i->d;
            if (temp_ticket.d >= dp[temp_ticket.v][temp_ticket.c])
            {
                continue;
            }
            pq.push(temp_ticket);
            dp[temp_ticket.v][temp_ticket.c] = temp_ticket.d;
        }
    }

    return -1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--)
    {
        int N, M, K;
        std::cin >> N >> M >> K;
        std::vector<std::vector<ticket>> tickets(N + 1, std::vector<ticket>());
        init_tickets(tickets, K);

        const int ans = solution(tickets, N, M);

        if (ans == -1)
        {
            std::cout << "Poor KCM";
        }
        else
        {
            std::cout << ans;
        }
    }
    return 0;
}