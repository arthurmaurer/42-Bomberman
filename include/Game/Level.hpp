
#ifndef _LEVEL_HPP
# define _LEVEL_HPP

# include <string>

class Block;

class Level
{
public:
	std::string		name;
	unsigned		width;
	unsigned		height;
	Block ***		map;

	Level(const std::string & name, unsigned width, unsigned height);
	~Level();

	void	registerNodes() const;
	void	unregisterNodes() const;
};

#endif /* _LEVEL_HPP */
