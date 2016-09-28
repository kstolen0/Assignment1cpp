#include "Watcher.h"

public ref class Watcher
{
private:
	// Define the event handlers


	static void OnChanged(Object^ /*source*/, FileSystemEventArgs^ e)
	{
		//	Load the watchlist file into a vector
		ifstream watchfile("watchList.txt");
		string line, temp, word;
		int pos;
		ifstream logfile("..\\Assignment1cpp\\wordlog.txt");

		if (logfile)
		{
			while (logfile >> ws && getline(logfile, temp));
		}
		else
		{
			cout << "File not found?" << endl;
			return;
		}

		pos = temp.find(" ");
		word = temp.substr(0, pos);

		while (getline(watchfile, line))
		{
			if (word == line)
			{
				cout << "Alert! Alert! " << word << " was searched for!" << endl;
			}
		}
	}

public:
	int static run()
	{
		// Create a new FileSystemWatcher and set its properties
		FileSystemWatcher^ watcher = gcnew FileSystemWatcher;
		watcher->Path = "..\\Assignment1cpp\\";

		// Watch for changes in LastAccess and LastWrite times, and
		// the renaming of files or directories
		watcher->NotifyFilter = static_cast<NotifyFilters>(NotifyFilters::LastAccess |
			NotifyFilters::LastWrite | NotifyFilters::FileName | NotifyFilters::DirectoryName);

		// Only watch the wordlog file
		watcher->Filter = "wordlog.txt";

		//Add onChanged event handler
		watcher->Changed += gcnew FileSystemEventHandler(Watcher::OnChanged);

		// Begin watching
		watcher->EnableRaisingEvents = true;

		// Wait for the user to quit the program
		Console::WriteLine("///////////////////////////");
		Console::WriteLine("//// Log File Watcher ////");
		Console::WriteLine("/////////////////////////\n");
		Console::WriteLine("Press \'q\' to stop watching.");
		char exit = ' ';
		while (exit != 'q')
		{
			exit = getch();
		}
		return 0;
	}
};

int main()
{
	Watcher::run();
}