#include "dataArray.h"
#include <vector>

namespace L3DPP {

void WriteDataArrayFloat4ToText(std::string filename, L3DPP::DataArray<float4>& segments) {
    std::ofstream outfile;
    outfile.open(filename.c_str());
    int n_segments = segments.width();
    outfile << n_segments << std::endl;
    for (int i = 0; i < n_segments; ++i) {
        const auto &d = segments.dataCPU(i, 0)[0];
        outfile<<d.x<<" "<<d.y<<" "<<d.z<<" "<<d.w<<std::endl;
    }
    outfile.close();
}
void ReadDataArrayFloat4FromText(std::string filename, L3DPP::DataArray<float4>& segments) {
    std::ifstream infile;
    infile.open(filename.c_str());
    int n_segments;
    infile >> n_segments;
    std::vector<float4> data(n_segments);
    for (int i = 0; i < n_segments; ++i) {
        float x, y, z, w;
        infile >> x >> y >> z >> w;
        data[i].x = x; data[i].y = y; data[i].z = z; data[i].w = w;
    }
    segments = L3DPP::DataArray<float4>(n_segments, 1);
    for (int i = 0; i < n_segments; ++i) {
        segments.dataCPU(i, 0)[0] = data[i];
    }
}

}
