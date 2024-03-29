#ifndef __LEVEL_SETTINGS_H__
#define __LEVEL_SETTINGS_H__

#include <vector>
#include <string>
#include <map>
#include "patterns/pattern.h"


class LevelSettings{
  int levelUpScore;
  int specialCount;
  int maxMoves;
  double lockedCellsPercent;
  std::string inputFile;

  // type -> probability
  std::map<std::string, double> typeProbabilities;
  // color -> probability
  std::map<std::string, double> colorProbabilities;

  std::vector<Pattern*> patterns;

  std::vector<std::string> colors;

  std::vector<std::string> types;

  public:
    LevelSettings();
    ~LevelSettings();

    void addType(std::string name, double prob=0);
    void addColor(std::string name, double prob=0);

    // accessor methods
    double getColorProbability(std::string) const;
    double getTypeProbability(std::string) const;
    std::map<std::string, double> getColorProbabilities() const;
    std::map<std::string, double> getTypeProbabilities() const;
    std::vector<std::string> getColors() const;
    std::vector<std::string> getTypes() const;
    std::vector<Pattern*> getPatterns() const;
    void registerPattern(Pattern* p);
    void setLevelUpScore(int l);
    int getLevelUpScore() const;
    void setSpecialCount(int c);
    int getSpecialCount() const;
    void setLockedCellsPercent(double p);
    double getLockedCellsPercent() const;
    void setInputFile(std::string name);
    void setMaxMoves(int m);
    int getMaxMoves();
    std::string getInputFile();
   
};

#endif