#include <bits/stdc++.h>

using namespace std;

typedef vector <pair <double , double> > vii;
typedef pair <double , double> ii;

double getDistOnSphare (double plat , double plong ,
                        double qlat , double qlong , double radius = 6378.0){
    double pi = 3.141592653589793;
    plat *= (pi /180.0);
    plong *= (pi /180.0);
    qlat *= (pi /180.0);
    qlong *= (pi /180.0);
    // long double Distance = acos( sin(plat) * sin(qlat) +
    //     cos(plat) * cos(qlat) * cos(plong) * cos(qlong) +
    //     cos(plat) * cos(qlat) * sin(plong) * sin(qlong)
    // ) * 10; // 6378 = R Of Earth

     return acos(cos(qlat) * cos(plat) * cos(plong - qlong) + sin(qlat) * sin(plat));
    //  return Distance;
}

int main (){
    int n;
    while (cin >> n){
        double lat,lon;
        vii airports;
        for (int i = 0 ; i < n ; i++){
            cin >> lat >> lon;
            airports.push_back(pair <double , double> (lat , lon));
        }
        ii best_airport;
        double mindist = 1000000000;
        for (int i = 0 ; i < n ; i++){
            ii current = airports[i];
            double maxdist = -1;
            for (int j = 0 ; j < n ; j++){
                double dist = getDistOnSphare (airports[i].first , airports[i].second,
                    airports[j].first, airports[j].second);

                if (dist > maxdist) maxdist = dist;
            }
            if (mindist > maxdist || abs(mindist - maxdist) < 1e-6){
                mindist = maxdist;
                best_airport = airports[i];
            }
        }
        cout << fixed << setprecision(2) << best_airport.first << " ";
        cout << fixed << setprecision(2) << best_airport.second << endl;
    }

    return 0;
}
