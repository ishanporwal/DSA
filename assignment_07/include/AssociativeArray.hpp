#include <vector>
#include <list>
#include <utility>
#include <functional>
#include <optional>

/**
 * Associative array implemented using a hash table with separate chaining.
 * @tparam K The key type
 * @tparam V The value type
 */
template <typename K, typename V>
class AssociativeArray {
private:
    std::vector<std::list<std::pair<K, V>>> buckets = std::vector<std::list<std::pair<K, V>>>(11);
    size_t numElements = 0;
    double sizeLimit = 0.75;

    /**
     * Calculates the bucket index for a given key.
     * @param key The key to hash
     * @return The bucket index
     */
    size_t hash(const K& key) const {
        size_t rawHash = std::hash<K>{}(key);
        return rawHash % buckets.size();
    }

    /**
     * Doubles the number of buckets and redistributes existing pairs.
     */
    void rehash() {
        size_t newCap = buckets.size() * 2;
        std::vector<std::list<std::pair<K, V>>> newBuckets(newCap);
        for (auto& list : buckets) {
            for (auto& pair : list) {
                size_t newIdx = std::hash<K>{}(pair.first) % newCap;
                newBuckets[newIdx].push_back(std::move(pair));
            }
        }
        buckets = std::move(newBuckets);
    }

public:
    /**
     * Creates an empty associative array with 11 buckets.
     */
    AssociativeArray() = default;

    /**
     * Inserts a key-value pair or updates the value if the key already exists.
     * Rehashes if the load factor exceeds 0.75.
     * @param key The key to insert or update
     * @param value The value to associate with the key
     */
    void set(const K& key, const V& value) {
        auto& list = buckets[hash(key)];
        for (auto& pair : list) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        list.push_back({key, value});
        numElements++;
        if (size() > sizeLimit * buckets.size()) {
            rehash();
        }
    }

    /**
     * Checks whether a key exists in the associative array.
     * @param key The key to search for
     * @return True if the key exists, false otherwise
     */
    bool contains(const K& key) const {
        const auto& list = buckets[hash(key)];
        for (const auto& pair : list) {
            if (pair.first == key) {
                return true;
            }
        }
        return false;
    }

    /**
     * Gets the value associated with a key.
     * @param key The key to search for
     * @return The associated value, or std::nullopt if the key doesn't exist
     */
    std::optional<V> get(const K& key) const {
        const auto& list = buckets[hash(key)]; 
        for (const auto& pair : list) { 
            if (pair.first == key) { 
                return pair.second; 
            } 
        } 
        return std::nullopt; 
    } 

    /**
     * Removes a key-value pair from the associative array.
     * @param key The key to remove
     * @return True if the key was removed, false if it wasn't found
     */
    bool remove(const K& key) {
        auto& list = buckets[hash(key)]; 
        for (auto it = list.begin(); it != list.end(); it++) { 
            if (it->first == key) { 
                list.erase(it); 
                numElements--; 
                return true; 
            } 
        } 
        return false; 
    } 

    /**
     * Gets the number of key-value pairs stored.
     * @return The number of elements
     */
    size_t size() const {
        return numElements;
    }

    /**
     * Returns all key-value pairs in the associative array.
     * @return A vector containing all stored key-value pairs
     */
    std::vector<std::pair<K, V>> keyValuePairs() const {
        std::vector<std::pair<K,V>> res;
        for (const auto& vec : buckets) {
            for (const auto& pair : vec) {
                res.push_back(pair);
            }
        }
        return res;
    }
};
