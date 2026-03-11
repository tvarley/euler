var assert = require('assert');
var solution039 = require('../src/euler/solution039');

describe('Solution039', function() {
  describe('answer', function() {
    it('will answer problem 039', function() {
      assert.equal(solution039.answer(), 840);
    });
  });
});