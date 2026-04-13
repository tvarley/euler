var assert = require('assert');
var solution086 = require('../src/euler/solution086');

describe('Solution086', function() {
  describe('answer', function() {
    it('will answer problem 086', function() {
      this.timeout(10000);
      assert.equal(solution086.answer(), 1818);
    });
  });
});