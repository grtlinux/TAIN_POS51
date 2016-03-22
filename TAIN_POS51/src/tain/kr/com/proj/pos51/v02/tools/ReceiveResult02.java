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
package tain.kr.com.proj.pos51.v02.tools;

import java.util.ResourceBundle;

import org.apache.log4j.Logger;

/**
 * Code Templates > Comments > Types
 *
 * <PRE>
 *   -. FileName   : ReceiveResult02.java
 *   -. Package    : tain.kr.com.proj.pos51.v02.tools
 *   -. Comment    :
 *   -. Author     : taincokr
 *   -. First Date : 2016. 3. 22. {time}
 * </PRE>
 *
 * @author taincokr
 *
 */
public class ReceiveResult02 extends Thread {

	private static boolean flag = true;

	private static final Logger log = Logger.getLogger(ReceiveResult02.class);

	///////////////////////////////////////////////////////////////////////////////////////////////
	
	private static final String THREAD_NAME = "RECEIVE_RESULT_02";
	
	private String clsName = null;
	
	
	public ReceiveResult02() throws Exception {
		
		super(THREAD_NAME);
		
		if (flag) {
			this.clsName = this.getClass().getName();
			
			ResourceBundle rb = ResourceBundle.getBundle(this.clsName.replace('.','/'));
			
		}
	}
	
	public void run() {
		
		if (flag) {
			
			try {
				
			} catch (Exception e) {
				//
				e.printStackTrace();
			} finally {
				
			}
		}
	}
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////

	private static void test01(String[] args) throws Exception {
		
		if (flag) {
			Thread thr = new ReceiveResult02();
			thr.start();
			thr.join();
		}
	}
	
	public static void main(String[] args) throws Exception {
		
		if (flag) log.debug(">>>>> " + new Object(){}.getClass().getEnclosingClass().getName());
		
		if (flag) test01(args);
	}
}
