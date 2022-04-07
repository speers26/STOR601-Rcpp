#include <Rcpp.h>
#include <unordered_map>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

typedef std::unordered_map<std::string,std::vector<std::string>> pref_table;
typedef std::unordered_map<std::string,std::string> match;

using namespace Rcpp;

// helper functions

pref_table convert(DataFrame input)
{

  std::unordered_map <std::string, std::vector<std::string>>  output;

  CharacterVector keys = input.names();
 
  for (int i=0; i<keys.size(); i++)
  {
    std::string key = as<std::string> (keys[i]);
    
    std::vector <std::string> values = input[key];
    
    output[key] = values;
  }
  return output;
}

// [[Rcpp::plugins(cpp17)]]
// [[Rcpp::export]]
CharacterVector fund(DataFrame male_pref2,DataFrame female_pref2)
{
  auto male_pref = convert(male_pref2);
  auto female_pref = convert(female_pref2);
  std::vector<std::string> males;
  std::vector<std::string> females;
  for (const auto& it: male_pref)
  {
    males.push_back(it.first);
  }
  for (const auto& it: female_pref)
  {
    females.push_back(it.first);
  }
  std::unordered_map<std::string,std::string> matching;
  std::string x;
  std::string X;
  std::string x_fiance;
  int ind_new;
  int ind_old;
  
  // first add the imaginary undesirable man 
  for (const auto& it : female_pref)
  {
    female_pref.at(it.first).push_back("O");
  }
  // engage all women to imaginary man
  for (const auto& it : females)
  {
    matching[it]="O";
  }
  // main loop
  for (const auto& it : males)
  {
    X = it;
    while (X!="O")
    {
      x = male_pref[X][0];
      x_fiance = matching[x];
      
      // find indices of current and potential spouse
      auto i = std::find(female_pref[x].begin(), female_pref[x].end(), x_fiance);
      ind_old = std::distance(female_pref[x].begin(), i);
      i = std::find(female_pref[x].begin(), female_pref[x].end(), X);
      ind_new = std::distance(female_pref[x].begin(), i);
      
      // pair female with current male if they prefer
      if (ind_new < ind_old)
      {
        matching[x]=X;
        X = x_fiance;
      }
      
      // if the man isn't imaginary, remove current best choice from his list
      if (X != "O")
      {
        male_pref[X].erase (male_pref[X].begin());
      }
    }
  }
  return wrap(matching);
}


