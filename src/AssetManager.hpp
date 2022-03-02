/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** FontManager
*/

#ifndef FONTMANAGER_HPP_
#define FONTMANAGER_HPP_

#include <SFML/Graphics.hpp>
#include <map>

template<typename T>
class AssetManager {
    public:
        ~AssetManager() {};

        /**
         * @brief Get the instance of the FontManager singelton
         *
         * @return ** FontManager &instance of FontManager
         */
        static AssetManager &getAssetManager() {
            static AssetManager instance = AssetManager();
            return instance;
        }

        /**
         * @brief Get asset, if asset already load just return the asset associeted to,
         * IMPORTANT !!!
         * if the type of asset doesn't have loadFromFile method, there will be an error
         *
         * @param path path to the font
         * @return ** template<typename T>
         */
        T getAsset(const std::string &path) {
            T asset;

            if (fonts.find(path) != fonts.end())
                return fonts[path];
            if (asset.loadFromFile(path))
                fonts.insert(std::pair<std::string, T>(path, asset));
            return asset;
        }

    protected:
    private:
        AssetManager() {};

        std::map<const std::string, T> fonts;
};

#endif /* !FONTMANAGER_HPP_ */