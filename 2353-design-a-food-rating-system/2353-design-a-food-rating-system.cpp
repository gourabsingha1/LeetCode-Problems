// changeRating = go back to its cuisine. find the pair of {oldRating, food}
// highestRated = store {-rating, food} then return begin()->second
// -rating makes sure that the highest rated food comes at begin()
// also when there is a tie in the rating, the lexicographically smallest food comes first

class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>>> adj;
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRating;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++)
        {
            adj[cuisines[i]].insert({-ratings[i], foods[i]});
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        auto it = adj[cuisine].find({-foodToRating[food], food});
        adj[cuisine].erase(it);
        adj[cuisine].insert({-newRating, food});
        foodToRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        auto it = adj[cuisine].begin();
        return it->second;
    }
};