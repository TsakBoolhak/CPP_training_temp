#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>

namespace _myTools {

	typedef enum e_ret_value {
		
		SUCCESS = 0,
		AV_IS_NULL = 1,
		AC_IS_INVALID = 2,
		INFILE_IS_INVALID = 3,
		OUTFILE_IS_INVALID = 4,
		EMPTY_TO_ERASE_FIELD = 5,
		ENUM_SIZE = 6
	} t_ret_value;

	void	replaceLoop( std::string &str , std::string &to_erase, std::string &to_insert) {

		std::size_t			found = 0;

		if (to_erase.empty())
			return ;
		while ( (found = str.find(to_erase, found)) != std::string::npos && found <= str.length())
		{

			str.erase(found, to_erase.length());
			str.insert(found, to_insert);
			found += to_insert.length();
		}

		return ;
	}

	bool	createReplaceFile( std::ofstream &outfile, char *filename ) {

			std::string			str;

			str.assign( filename );
			str += ".replace";
			outfile.open( str.c_str() , std::ofstream::out );

			if ( outfile.fail() )
				return false;
			else
				return true;
	}

	void	coreReplace (std::ifstream &infile, std::ofstream &outfile, std::string to_erase, std::string to_insert) {

		std::string	str;
		std::stringstream	strStream;

		strStream << infile.rdbuf();
		str.assign( strStream.str() );
		infile.close();

		_myTools::replaceLoop(str, to_erase, to_insert);

		strStream.str (str);
		outfile << strStream.rdbuf();
		outfile.close();

	}

	int	coreProgram( int ac, char **av ) {

		if (!av)
			return _myTools::AV_IS_NULL;

		else if ( ac != 4 )
			return _myTools::AC_IS_INVALID;

		else if (*(av[2]) == '\0')
			return _myTools::EMPTY_TO_ERASE_FIELD;
		else {

			std::ifstream		infile;

			infile.open( av[1], std::ifstream::in );

			if ( infile.fail() )
				return _myTools::INFILE_IS_INVALID;

			else {

				std::ofstream		outfile;

				if ( _myTools::createReplaceFile( outfile, av[1] ) == false ) {

					infile.close();
					return _myTools::OUTFILE_IS_INVALID;
				}

				else {

					_myTools::coreReplace(infile, outfile, av[2], av[3]);

					return _myTools::SUCCESS;
				}
			}
		}
	}

	void	displayStatusMessage(int ret, int ac, char **av) {

		const char	*message[] = {
		
			"Everything went well",
			"Somehow argv is NULL",
			"Invalid number of arguments",
			"Invalid infile",
			"Couldn't create outfile",
			"Second argument can not be empty"
		};

		if (ret < _myTools::SUCCESS || ret >= _myTools::ENUM_SIZE)
			std::cout << "Unkown error" << std::endl;
		else {

			std::stringstream strStream;

			strStream << message[ret] << std::endl;
			switch (ret) {

				case SUCCESS:
					strStream << av[1] << ".replace file was created and contain a copy of " << av[1] << " with all occurences of \"" << av[2] << "\" replaced by \"" << av[3] << '\"' << std::endl;
					break;
				case AC_IS_INVALID:
					strStream << "you entered " << ac - 1 << " arguments instead of 3" << std::endl;
					break;
				case INFILE_IS_INVALID:
					strStream << "Could not open the file " << av[1] << std::endl;
					break;
				case OUTFILE_IS_INVALID:
					strStream << "Couldnt create the file " << av[1] << ".replace" << std::endl;
					break;
				default:
					break;

			}

			std::cout << strStream.str() << std::endl;
		}
	}

};


int	main ( int ac, char **av ) {

	int	ret = _myTools::coreProgram( ac, av );

	_myTools::displayStatusMessage(ret, ac, av);

	return ret;
}
