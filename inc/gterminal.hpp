#ifndef __WALKER_GTERMINAL__
#define __WALKER_GTERMINAL__


namespace walker {

	/* Switches terminal input into raw.
	 * */
	void activate_raw_input();

	/* Restores terminal original input.
	 *
	 * Dont run this manually.
	 * */
	void __restore_input();

}

#endif
