/**
 * Copyright 2014, 2015, 2016 TAIN, Inc. all rights reserved.
 *
 * Licensed under the GNU GENERAL PUBLIC LICENSE, Version 3, 29 June 2007 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.gnu.org/licenses/
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * -----------------------------------------------------------------
 * Copyright 2014, 2015, 2016 TAIN, Inc.
 *
 */
package tain.kr.com.proj.pos51.v01.main;

import org.apache.log4j.Logger;

/**
 * Code Templates > Comments > Types
 *
 * <PRE>
 *   -. FileName   : ThreadPOSHW000002.java
 *   -. Package    : tain.kr.com.proj.pos51.main
 *   -. Comment    :
 *   -. Author     : taincokr
 *   -. First Date : 2016. 3. 21. {time}
 * </PRE>
 *
 * @author taincokr
 *
 */
public class ThreadPOSHW000002 extends Thread {

	private static boolean flag = true;

	private static final Logger log = Logger.getLogger(ThreadPOSHW000002.class);

	///////////////////////////////////////////////////////////////////////////////////////////////
	
	public ThreadPOSHW000002() {
		
		if (flag) log.debug(">>>>> " + this.getClass().getName());
	}
	
	public void run() {
		
		if (flag) {
			
		}
		
		if (flag) {
			try { Thread.sleep(1000); } catch (InterruptedException e) {}
		}
	}
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////

}
