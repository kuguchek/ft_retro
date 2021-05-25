#ifndef ELEMENTS_HPP
# define ELEMENTS_HPP

class Elements {
	public:
		Elements() : _posX(0), _posY(0) {} //Star(posX, posY)
		Elements(Elements const& src) {
			_posX = src._posX;
			_posY = src._posY;
		}

		Elements & operator=(Elements const& src) {
			if (this != &src) {
				_posX = src._posX;
				_posY = src._posY;
			}
			return *this;
		}
		virtual ~Elements() {}
		//virtual void	move(void) = 0;
		//virtual void	spawn(void) = 0;
		virtual void	print(void)		const = 0;
		int 	getPosX(void)	const {
			return _posX;
		}
		int		getPosY(void)	const {
			return _posY;
		}
	protected:
		int _posX;
		int _posY;
};

#endif