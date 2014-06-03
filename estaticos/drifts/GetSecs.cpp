int Drifts::get_secs(){
	time_t now;
	struct tm *tm;

	now = time(0);

	tm = localtime(&now);

	return tm->tm_sec;
}