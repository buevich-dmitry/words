#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>
#include <iostream>
#include <string>

#include "text_processing.h"

namespace po = boost::program_options;
namespace fs = boost::filesystem;

std::vector<std::string> ReadFile(const std::string& file_name) {
    fs::ifstream input(file_name);
    std::vector<std::string> result;
    std::string line;
    while (std::getline(input, line)) {
        result.push_back(line);
    }
    return result;
}

void WriteFile(const std::string& file_name, const std::vector<std::string>& lines) {
    fs::ofstream output(file_name);
    for (const auto& line : lines) {
        output << line << '\n';
    }
}

int main(int ac, char **av) {
    po::options_description desc("Allowed options");
    desc.add_options()
            ("help,h", "produce help message")
            ("input-file,i", po::value<std::string>(), "path to input file")
            ("output-file,o", po::value<std::string>(), "path to output file")
            ("word,w", po::value<std::string>(), "word to be deleted");

    po::variables_map vm;
    po::store(po::parse_command_line(ac, av, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }

    if (!vm.count("input-file") || !vm.count("output-file") || !vm.count("word")) {
        std::cout << "Not all required argumets are provided. Use --help option for more details\n";
        return 1;
    }

    const auto input_file = vm["input-file"].as<std::string>();
    const auto output_file = vm["output-file"].as<std::string>();
    const auto word = vm["word"].as<std::string>();

    if (!fs::exists(input_file)) {
        std::cout << "Input file does not exist\n";
        return 1;
    }

    const auto lines = ReadFile(input_file);
    const auto processed_lines = ProcessLines(lines, word);
    WriteFile(output_file, processed_lines);

    return 0;
}